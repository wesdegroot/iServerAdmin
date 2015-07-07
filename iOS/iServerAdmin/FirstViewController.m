//
//  FirstViewController.m
//  iServerAdmin
//
//  Created by Wesley de Groot on 07-07-15.
//  Copyright © 2015 Wesley de Groot. All rights reserved.
//

#import "FirstViewController.h"
#import "../../Resources/NSString_NSStringExt.h"

@interface FirstViewController ()

@end

@implementation FirstViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    NSString *username = @"test";
    NSString *password = @"test";
    NSString *post =[NSString stringWithFormat:@"username=%@&password=%@", username, password];
    
    NSString *test = [@"https://www.wdgp.nl:2222/CMD_LOGIN" post:post];
    NSLog(@"--> %@", test);
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
