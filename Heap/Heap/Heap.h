//
//  Heap.h
//  Heap
//
//  Created by wangwei on 2019/6/12.
//  Copyright © 2019 WW. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef int(^Comparator)(id value1,id value2);

@interface Heap : NSObject

- (id)initWithComparator:(Comparator)comparator;
- (id)initWithArray:(NSArray *)array comparator:(Comparator)comparator;
- (void)add:(id)objc;
- (id)remove;
- (id)peek;
- (id)replace:(id)objc;
- (NSUInteger)size;
- (BOOL)isEmpty;
@end

NS_ASSUME_NONNULL_END
