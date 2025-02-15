//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Any object whose state can be validated for correctness.
 *
 * Typically this will be implemented only by data-model classes.
*/
@protocol BDPValidatable <NSObject>

/**
 * @returns YES if the state of this object is valid, NO otherwise.
 */
- (BOOL)valid;

@end
