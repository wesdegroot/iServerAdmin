//
//  DetailViewController.h
//  iServerAdmin
//
//  Created by Wesley de Groot on 06-07-15.
//  Copyright © 2015 Wesley de Groot. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DetailViewController : UIViewController

@property (strong, nonatomic) id detailItem;
@property (weak, nonatomic) IBOutlet UILabel *detailDescriptionLabel;

@end

