//
//  BinarySearchTree.h
//  BinarySearchTree
//
//  Created by wangwei on 2019/5/13.
//  Copyright © 2019 WW. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef int(^Comparator)(id objc1,id objc2);

@interface TreeNode : NSObject
@property(nonatomic,strong)id element;
@property(nonatomic,strong)TreeNode * _Nullable left;
@property(nonatomic,strong)TreeNode * _Nullable right;
@property(nonatomic,weak)TreeNode *parent;
- (instancetype)initWithElement:(id)element left:(nullable TreeNode *)left andRight:(nullable TreeNode *)right;
- (NSUInteger)getDegree;
@end

@interface BinarySearchTree : NSObject
{
    @protected TreeNode *_root;
}
@property(nonatomic,copy,readonly)Comparator comparator;

- (instancetype)initWithComparator:(Comparator)comparator;
- (TreeNode *)createNode:(id)objc;
- (void)add:(id)objc;
- (void)afterAdd:(TreeNode *)node;
- (void)afterRemove:(TreeNode *)node;
- (void)remove:(id)objc;
- (void)preOrderTraversalUsingBlock:(void (^)(id obj, BOOL *stop))block;
- (void)preOrderTraversalUsingBlock1:(void (^)(id obj, BOOL *stop))block;
- (void)inOrderTraversalUsingBlock:(void (^)(id obj, BOOL *stop))block;
- (void)inOrderTraversalUsingBlock1:(void (^)(id obj, BOOL *stop))block;
- (void)postOrderTraversalUsingBlock:(void (^)(id obj, BOOL *stop))block;
- (void)postOrderTraversalUsingBlock1:(void (^)(id obj, BOOL *stop))block;
- (void)levelOrderTraversalUsingBlock:(void (^)(id obj, BOOL *stop))block;
- (NSUInteger)height;
- (NSUInteger)size;
- (void)clean;
- (BOOL)contain:(id)objc;

@end

NS_ASSUME_NONNULL_END
