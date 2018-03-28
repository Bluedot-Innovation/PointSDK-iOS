//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface NSString (BDURLEncoding)

//  Methods for encoding and decoding a URL
- (NSString *)urlEncodeUsingEncoding: (NSStringEncoding)encoding;
- (NSString *)urlDecode;

@end
