//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
  @brief Any object having a human-readable name and description, typically for display in a User Interface.
  @copyright Bluedot Innovation
*/
@protocol BDPNamedDescribed

/** Human-readable name of this object. */
@property (copy) NSString  *name;

/** Human-readable description for this object. */
@property (copy,readwrite) NSString *description;

@end
