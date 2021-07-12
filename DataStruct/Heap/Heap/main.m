//
//  main.m
//  Heap
//
//  Created by wangwei on 2019/6/12.
//  Copyright © 2019 WW. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Heap.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        
        NSMutableArray *array = [NSMutableArray array];
        [array addObject:@(32)];
        [array addObject:@(42)];
        [array addObject:@(36)];
        [array addObject:@(13)];
        [array addObject:@(132)];
        [array addObject:@(562)];
        [array addObject:@(-32)];
        [array addObject:@(3552)];
        [array addObject:@(12)];
        [array addObject:@(152)];
        [array addObject:@(2)];
        [array addObject:@(355)];
        [array addObject:@(-352)];
        [array addObject:@(-52)];
        
        Heap *heap = [[Heap alloc] initWithArray:array comparator:^int(id  _Nonnull value1, id  _Nonnull value2) {
            return [value1 unsignedIntValue] - [value2 unsignedIntValue];
        }];
        NSUInteger size = [heap size];
        for (NSUInteger i = 0; i < size; i ++) {
            NSLog(@"remove:%@",[heap remove]);
        }
        
    }
    return 0;
}
