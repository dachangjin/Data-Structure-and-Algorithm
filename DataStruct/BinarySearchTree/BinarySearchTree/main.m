//
//  main.m
//  BinarySearchTree
//
//  Created by wangwei on 2019/5/17.
//  Copyright © 2019 WW. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BinarySearchTree.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        BinarySearchTree *tree = [[BinarySearchTree alloc] initWithComparator:^int(id  _Nonnull objc1, id  _Nonnull objc2) {
            NSNumber *num1 = objc1;
            NSNumber *num2 = objc2;
            if([num1 integerValue] > [num2 integerValue]){
                return 1;
            }else if ([num1 integerValue] < [num2 integerValue]){
                return -1;
            }else{
                return 0;
            }
        }];
        for (int i = 0; i < 1000; i ++) {
            [tree add:[NSNumber numberWithInt:arc4random() % 1000]];
        }
        [tree inOrderTraversalUsingBlock:^(id  _Nonnull obj, BOOL * _Nonnull stop) {
            NSNumber *num = obj;
            NSLog(@"%@",num);
        }];
        NSLog(@"size:%lu",(unsigned long)[tree size]);
        NSLog(@"~~~~~~~~~~~~~~~~~~~~~~~");
        [tree remove:@(43)];
        [tree inOrderTraversalUsingBlock:^(id  _Nonnull obj, BOOL * _Nonnull stop) {
            NSNumber *num = obj;
            NSLog(@"%@",num);
        }];
        NSLog(@"size:%lu",(unsigned long)[tree size]);
        
        NSLog(@"height:%lu",(unsigned long)[tree height]);

        
    }
    return 0;
}
