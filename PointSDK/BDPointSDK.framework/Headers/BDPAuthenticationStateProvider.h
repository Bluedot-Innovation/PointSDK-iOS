//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BDAuthenticationState.h"

/**
@brief Describes an object which can provide an authentication state.  Currently @ref BDLocationManager(BDPointSDK).
*/
@protocol BDPAuthenticationStateProvider <NSObject>

/**
* This property must have a KVO-compliant implementation.
*/
@property (readonly) BDAuthenticationState authenticationState;

@end
