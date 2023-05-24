//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Thrown when the <b>Point SDK</b> session life-cycle or initialization state has been violated.
*/
@interface BDPointSessionException : NSException

/**
 * Shorthand to create ``NSException`` for a reason.
 */
+ (NSException *)exceptionWithReason:(NSString*)reason;

@end
