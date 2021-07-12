//
//  AVLTree.m
//  AVLTree
//
//  Created by wangwei on 2019/5/31.
//  Copyright © 2019 WW. All rights reserved.
//

#import "AVLTree.h"

@interface AVLTreeNode : TreeNode
@property(nonatomic,assign)NSUInteger height;


- (BOOL)isLeftChild;
- (int)balanceFactor;
- (void)updateHeight;
- (AVLTreeNode *)tallerChild;
@end

@implementation AVLTreeNode

-(instancetype)initWithElement:(id)element left:(TreeNode *)left andRight:(TreeNode *)right
{
    if (self = [super initWithElement:element left:left andRight:right]) {
        _height = 1;
    }
    return self;
}

- (int)balanceFactor
{
    AVLTreeNode *leftNode = (AVLTreeNode *)self.left;
    AVLTreeNode *rightNode = (AVLTreeNode *)self.right;
    int leftHeight = leftNode == nil ? 0 : (int)leftNode.height;
    int rightHeight = rightNode == nil ? 0 : (int)rightNode.height;
    return leftHeight - rightHeight;
}

- (void)updateHeight
{
    AVLTreeNode *leftNode = (AVLTreeNode *)self.left;
    AVLTreeNode *rightNode = (AVLTreeNode *)self.right;
    NSUInteger leftHeight = leftNode == nil ? 0 : leftNode.height;
    NSUInteger rightHeight = rightNode == nil ? 0 : rightNode.height;
    self.height = 1 + MAX(leftHeight, rightHeight);
}

- (AVLTreeNode *)tallerChild
{
    AVLTreeNode *leftNode = (AVLTreeNode *)self.left;
    AVLTreeNode *rightNode = (AVLTreeNode *)self.right;
    NSUInteger leftHeight = leftNode == nil ? 0 : leftNode.height;
    NSUInteger rightHeight = rightNode == nil ? 0 : rightNode.height;
    if(leftHeight > rightHeight) return leftNode;
    if(rightHeight > leftHeight) return rightNode;
    return [self isLeftChild] ? leftNode : rightNode;
}

- (BOOL)isLeftChild
{
    if (!self.parent) return NO;
    return self == self.parent.left;
}

@end

@implementation AVLTree

- (TreeNode *)createNode:(id)objc
{
    return [[AVLTreeNode alloc] initWithElement:objc left:nil andRight:nil];
}

- (void)afterAdd:(TreeNode *)node
{
    while ((node = node.parent) != nil) {
        if ([self isBalanced:(AVLTreeNode *)node]) {
            //更新节点高度
            [self updateNodeHeight:(AVLTreeNode *)node];
        }else{
            //恢复节点平衡,恢复后整棵树的平衡也恢复了
            [self rebalanceNode:(AVLTreeNode *)node];
            break;
        }
    }
}


- (void)afterRemove:(TreeNode *)node
{
    while ((node = node.parent) != nil) {
        if ([self isBalanced:(AVLTreeNode *)node]) {
            //更新节点高度
            [self updateNodeHeight:(AVLTreeNode *)node];
        }else{
            //恢复节点平衡,恢复后可能造成父节点又失去平衡
            [self rebalanceNode:(AVLTreeNode *)node];
        }
    }
}


//节点是否平衡
- (BOOL)isBalanced:(AVLTreeNode *)node
{
    return abs([node balanceFactor]) <= 1;
}

//更新节点高度
- (void)updateNodeHeight:(AVLTreeNode *)node
{
    [node updateHeight];
}

//恢复节点平衡
- (void)rebalanceNode:(AVLTreeNode *)grand
{
    AVLTreeNode *parent = [grand tallerChild];
    AVLTreeNode *node = [parent tallerChild];
    if ([parent isLeftChild]) {//L
        if ([node isLeftChild]) {//LL
            [self rightRotate:grand];
        }else{//LR
            [self leftRotate:parent];
            [self rightRotate:grand];
        }
    }else{//R
        if ([node isLeftChild]) {//RL
            [self rightRotate:parent];
            [self leftRotate:grand];
        }else{//RR
            [self leftRotate:grand];
        }
    }
}


/**
 左旋
 @param node 节点
 */
- (void)leftRotate:(AVLTreeNode *)node
{
    //node为根节点
    TreeNode *parent = node.parent;
    BOOL isLeftChild = [node isLeftChild];
    TreeNode *rightChild = node.right;//新的头结点
    TreeNode *rightChildleftChild = rightChild.left;
    rightChild.left = node;
    node.parent = rightChild;
    node.right = rightChildleftChild;
    [self updateNodeHeight:node];
    if (rightChildleftChild) {
        rightChildleftChild.parent = node;
    }
    if (parent) {//不为根节点
        if (isLeftChild) {
            parent.left = rightChild;
        }else{
            parent.right = rightChild;
        }
        rightChild.parent = parent;
    }else{//根节点
        _root = rightChild;
        rightChild.parent = nil;
    }
    [self updateNodeHeight:(AVLTreeNode *)rightChild];
}


/**
 右旋
 @param node 节点
 */
- (void)rightRotate:(AVLTreeNode *)node
{
    //node为根节点
    TreeNode *parent = node.parent;
    BOOL isLeftChild = [node isLeftChild];
    TreeNode *leftChild = node.left;//新的头结点
    TreeNode *leftChildRightChild = leftChild.right;
    leftChild.right = node;
    node.parent = leftChild;
    node.left = leftChildRightChild;
    [self updateNodeHeight:node];
    if (leftChildRightChild) {
        leftChildRightChild.parent = node;
    }
    if (parent) {//不为根节点
        if (isLeftChild) {
            parent.left = leftChild;
        }else{
            parent.right = leftChild;
        }
        leftChild.parent = parent;
    }else{//根节点
        _root = leftChild;
        leftChild.parent = nil;
    }
    [self updateNodeHeight:(AVLTreeNode *)leftChild];
}

@end
