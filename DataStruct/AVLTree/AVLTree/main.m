//
//  main.m
//  AVLTree
//
//  Created by wangwei on 2019/5/31.
//  Copyright © 2019 WW. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AVLTree.h"
int main(int argc, const char * argv[]) {
    @autoreleasepool {
        BinarySearchTree *tree1 = [[BinarySearchTree alloc] initWithComparator:^int(id  _Nonnull objc1, id  _Nonnull objc2) {
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
        
        AVLTree *tree2 = [[AVLTree alloc] initWithComparator:^int(id  _Nonnull objc1, id  _Nonnull objc2) {
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
        for (int i = 0; i < 100; i ++) {
            NSNumber *number = [NSNumber numberWithInt:arc4random() % 100];
            [tree1 add:number];
            [tree2 add:number];
        }
        [tree1 postOrderTraversalUsingBlock:^(id  _Nonnull obj, BOOL * _Nonnull stop) {
            NSNumber *num = obj;
            NSLog(@"%@",num);
        }];
        NSLog(@"~~~~~~~~~~~~~~~~~~~~~~~");
        [tree1 postOrderTraversalUsingBlock1:^(id  _Nonnull obj, BOOL * _Nonnull stop) {
            NSNumber *num = obj;
            NSLog(@"%@",num);
        }];
        NSLog(@"size:%lu",(unsigned long)[tree1 size]);
        NSLog(@"height:%lu",(unsigned long)[tree1 height]);
        NSLog(@"~~~~~~~~~~~~~~~~~~~~~~~");

        [tree2 inOrderTraversalUsingBlock:^(id  _Nonnull obj, BOOL * _Nonnull stop) {
            NSNumber *num = obj;
            NSLog(@"%@",num);
        }];
        NSLog(@"size:%lu",(unsigned long)[tree2 size]);
        NSLog(@"height:%lu",(unsigned long)[tree2 height]);
        
        NSLog(@"%d,%d",[tree1 contain:@(22)],
              [tree1 contain:@(22)]);
        
        NSLog(@"~~~~~~~~~~~~~~~~~~~~~~~");
        
        [tree1 clean];
        [tree2 clean];

        NSLog(@"size:%lu",(unsigned long)[tree1 size]);
        NSLog(@"height:%lu",(unsigned long)[tree1 height]);
        NSLog(@"size:%lu",(unsigned long)[tree2 size]);
        NSLog(@"height:%lu",(unsigned long)[tree2 height]);
    }
    return 0;
}
