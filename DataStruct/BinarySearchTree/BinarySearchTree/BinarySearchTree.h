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
@interface BinarySearchTree : NSObject
- (instancetype)initWithComparator:(Comparator)comparator;
- (void)add:(id)objc;
- (void)remove:(id)objc;
- (void)preOrderTraversalUsingBlock:(void (^)(id obj, BOOL *stop))block;
- (void)inOrderTraversalUsingBlock:(void (^)(id obj, BOOL *stop))block;
- (void)postOrderTraversalUsingBlock:(void (^)(id obj, BOOL *stop))block;
- (void)levelOrderTraversalUsingBlock:(void (^)(id obj, BOOL *stop))block;
- (NSUInteger)height;
- (NSUInteger)size;
- (void)clean;
- (BOOL)contain:(id)objc;
@end

NS_ASSUME_NONNULL_END
