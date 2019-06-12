//
//  RBTree.m
//  RBTree
//
//  Created by wangwei on 2019/5/31.
//  Copyright © 2019 WW. All rights reserved.
//

#import "RBTree.h"

static BOOL RED = YES;
static BOOL BLACK = NO;

@interface RBTreeNode : TreeNode
@property(nonatomic,assign)BOOL color;

@end

@implementation RBTreeNode
-(instancetype)initWithElement:(id)element left:(TreeNode *)left andRight:(TreeNode *)right
{
    if (self = [super initWithElement:element left:left andRight:right]) {
        _color = RED;
    }
    return self;
}
@end


@implementation RBTree

- (TreeNode *)createNode:(id)objc
{
    return [[RBTreeNode alloc] initWithElement:objc left:nil andRight:nil];
}

- (void)colorRed:(RBTreeNode *)node
{
    if(!node) return;
    node.color = RED;
}

- (void)colorBlack:(RBTreeNode *)node
{
    if (!node) return;
    node.color = BLACK;
}

@end
