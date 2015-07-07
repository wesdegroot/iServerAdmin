//
//  NSString_NSStringExt.h
//  iServerAdmin
//
//  Created by Wesley de Groot on 07-07-15.
//  Copyright © 2015 Wesley de Groot. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface NSString(urlPost)

-(NSString*) post:(NSString *)poststr;

@end

@implementation NSString(urlPost)

-(NSString*) post:(NSString *)poststr
{
    NSData *postData = [poststr dataUsingEncoding:NSASCIIStringEncoding allowLossyConversion:YES];
    
    NSString *postLength = [NSString stringWithFormat:@"%lu", (unsigned long)[postData length]];
    
    NSMutableURLRequest *request = [[NSMutableURLRequest alloc] init];
    
    [request setURL:[NSURL URLWithString:self]];
    [request setHTTPMethod:@"POST"];
    [request setValue:postLength forHTTPHeaderField:@"Content-Length"];
    [request setValue:@"application/x-www-form-urlencoded" forHTTPHeaderField:@"Content-Type"];
    [request setHTTPBody:postData];
    [request setHTTPShouldHandleCookies:YES];
    
    [[NSURLSession sharedSession] downloadTaskWithRequest:request completionHandler:^(NSURL * __nullable location, NSURLResponse * __nullable response, NSError * __nullable error) {
        NSLog(@"X %@", response);
    }];
    
    [[NSURLSession sharedSession] dataTaskWithRequest:request
                                    completionHandler:^(NSData * __nullable data, NSURLResponse * __nullable response, NSError * __nullable error)
    {
        NSLog(@"[WEB] Response Code: %@", response);
//        
//        if ([response statusCode] >= 200 && [response statusCode] < 300)
//        {
//            //NSHTTPCookie *cookie = [[[NSHTTPCookieStorage sharedHTTPCookieStorage] cookies] objectAtIndex:0];
//            //if (![[cookie value] isEqualToString:@""])
//            //{
//            
//            NSString     *result = [[NSString alloc] initWithData:data
//                                                         encoding:NSUTF8StringEncoding];
//
//            return result;
//            //}
//        }
//        
//        return [NSString stringWithFormat:@"Error %ld.", (long)[urlResponse statusCode]];

    }];
    //return nil;
            return nil;
}

@end
