//
//  BinarySearchTree.m
//  BinarySearchTree
//
//  Created by wangwei on 2019/5/13.
//  Copyright © 2019 WW. All rights reserved.
//

#import "BinarySearchTree.h"



@implementation TreeNode
- (instancetype)initWithElement:(id)element left:(TreeNode *)left andRight:(TreeNode *)right
{
    if (self = [super init]) {
        _element = element;
        _left = left;
        _right = right;
    }
    return self;
}

- (NSUInteger)getDegree
{
    if (_left && _right) {
        return 2;
    }else if (_left || _right){
        return 1;
    }else{
        return 0;
    }
}
@end

@interface BinarySearchTree ()

@property(nonatomic,assign)NSUInteger size;

@end

@implementation BinarySearchTree
- (instancetype)initWithComparator:(Comparator)comparator
{
    NSAssert(comparator, @"invalid comparator");
    if(self = [super init]){
        _comparator = comparator;
        _size = 0;
    }
    return self;
}

- (TreeNode *)createNode:(id)objc
{
    TreeNode *node = [[TreeNode alloc] initWithElement:objc left:nil andRight:nil];
    return node;
}


- (void)add:(id)objc
{
    if(!_root){
        _root = [self createNode:objc];
        _root.parent = nil;
        return;
    }
    TreeNode *parent = _root;
    TreeNode *temp = _root;
    int result = 0;
    while (temp != nil) {
        parent = temp;
        result = _comparator(temp.element,objc);
        if (result > 0) {
            temp = temp.left;
        }else if (result < 0){
            temp = temp.right;
        }else{
            temp.element = objc;
            return;
        }
    }
    TreeNode *node = [self createNode:objc];
    node.parent = parent;
    if (result > 0) {
        parent.left = node;
    }else{
        parent.right = node;
    }
    _size++;
    [self afterAdd:node];
}

- (void)afterAdd:(TreeNode *)node
{
    
}

- (void)afterRemove:(TreeNode *)node
{
    
}

- (void)remove:(id)objc
{
    if (!objc) return;
    [self removeNode:[self getNode:objc]];
}

//度为2的节点的前驱或后继节点的度一定为1或者0，可先找到前驱或后继，将前驱或后继的element赋值给node，然后删除前驱或后继。即将问题简化删除度为1或0的问题
- (void)removeNode:(TreeNode *)node
{
    if (!node) return;
    _size--;
    //找到后继,将后继的element赋值给node，并将node指向后继。将问题转化为删除后继（度为0或者1）
    if ([node getDegree] == 2) {
        TreeNode *suc = [self successor:node];
        node.element = suc.element;
        node = suc;
    }
    TreeNode *son = node.left ? node.left : node.right;
    if (son) {
        //删除度为1的节点
        if (!node.parent) {
            //node为根节点
            _root = son;
        }else if (node.parent.left == node){
            //node是父节点的left
            node.parent.left = son;
        }else{
            //node是父节点的right
            node.parent.right = son;
        }
    }else if(node.parent){
        //node是叶子节点，但不是root
        if (node.parent.left == node) {
            node.parent.left = nil;
        }else{
            node.parent.right = nil;
        }
    }else{
        //node是root
        _root = nil;
    }
}


- (void)preOrderTraversalUsingBlock:(void (^)(id obj, BOOL *stop))block
{
    if (!block) return;
    BOOL stop = NO;
    [self preOrderTraversalNode:_root block:block stop:&stop];
}

- (void)inOrderTraversalUsingBlock:(void (^)(id obj, BOOL *stop))block
{
    if (!block) return;
    BOOL stop = NO;
    [self inOrderTraversalNode:_root block:block stop:&stop];
}

- (void)postOrderTraversalUsingBlock:(void (^)(id obj, BOOL *stop))block
{
    if (!block) return;
    BOOL stop = NO;
    [self postOrderTraversalNode:_root block:block stop:&stop];
}

- (void)levelOrderTraversalUsingBlock:(void (^)(id obj, BOOL *stop))block
{
    if (!block) return;
    BOOL stop = NO;
    [self levelOrderTraversalNode:_root block:block stop:&stop];
}

- (void)preOrderTraversalNode:(TreeNode *)node block:(void (^)(id obj, BOOL *stop))block stop:(BOOL *)stop
{
    if (!node) return;
    if (*stop) return;
    block(node.element,stop);
    [self preOrderTraversalNode:node.left block:block stop:stop];
    [self preOrderTraversalNode:node.right block:block stop:stop];
    
}

- (void)inOrderTraversalNode:(TreeNode *)node block:(void (^)(id obj, BOOL *stop))block stop:(BOOL *)stop
{
    if (!node) return;
    [self inOrderTraversalNode:node.left block:block stop:stop];
    if (*stop) return;
    block(node.element,stop);
    [self inOrderTraversalNode:node.right block:block stop:stop];
    
}


- (void)postOrderTraversalNode:(TreeNode *)node block:(void (^)(id obj, BOOL *stop))block stop:(BOOL *)stop
{
    if (!node) return;
    [self postOrderTraversalNode:node.left block:block stop:stop];
    [self postOrderTraversalNode:node.right block:block stop:stop];
    if (*stop) return;
    block(node.element,stop);
}

- (void)levelOrderTraversalNode:(TreeNode *)node block:(void (^)(id obj, BOOL *stop))block stop:(BOOL *)stop
{
    if (!node) return;
    NSMutableArray *queue = [NSMutableArray array];
    [queue addObject:node];
    while (queue.count) {
        TreeNode *node = [queue objectAtIndex:0];
        [queue removeObject:node];
        block(node.element,stop);
        if (*stop) return;
        if (node.left) {
            [queue addObject:node.left];
        }
        if (node.right) {
            [queue addObject:node.right];
        }
    }
}

- (NSUInteger)height
{
    if(!_root) return 0;
    NSUInteger height = 0;
    NSUInteger levelSize = 1;
    NSMutableArray *queue = [NSMutableArray array];
    [queue addObject:_root];
    while (queue.count) {
        TreeNode *node = [queue firstObject];
        [queue removeObject:node];
        levelSize --;
        if (node.left) {
            [queue addObject:node.left];
        }
        if (node.right) {
            [queue addObject:node.right];
        }
        if (levelSize == 0) {
            height ++;
            levelSize = [queue count];
        }
    }
    return height;
}

- (NSUInteger)size
{
    return _size;
}

- (TreeNode *)getNode:(id)element
{
    if (!element) return nil;
    TreeNode *node = _root;
    while (node) {
        int result = _comparator(node.element,element);
        if (result > 0) {
            node = node.left;
        }else if (result < 0){
            node = node.right;
        }else{
            return node;
        }
    }
    return node;
}

- (TreeNode *)predecessor:(TreeNode *)node
{
    if (!node) return nil;
    TreeNode *p = node;
    //子节点中查找
    if (p.left) {
        p = p.left;
        while (p.right) {
            p = p.right;
        }
        return p;
    }
    //父节点中查找
    if (!p.parent){
        return nil;
    }else if(p.parent.right == p){
        return p.parent;
    }else{
        while (p.parent && p.parent.left == p) {
            p = p.parent;
        }
        return p.parent;
    }
}

- (TreeNode *)successor:(TreeNode *)node
{
    if (!node) return nil;
    TreeNode *p = node;
    //子节点中查找
    if (p.right) {
        p = p.right;
        while (p.left) {
            p = p.left;
        }
        return p;
    }
    //父节点中查找
    if (!p.parent) {
        return nil;
    }else if (p.parent.left == p){
        return p.left;
    }else{
        while (p.parent && p.parent.right == p) {
            p = p.parent;
        }
        return p.parent;
    }
}

- (void)clean
{
    if (_root) {
        _root = nil;
        _size = 0;
    }
}

- (BOOL)contain:(id)objc
{
    return [self getNode:objc] != nil;
}
@end
