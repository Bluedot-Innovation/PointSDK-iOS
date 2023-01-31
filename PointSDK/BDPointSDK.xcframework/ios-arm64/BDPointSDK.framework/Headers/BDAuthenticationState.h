//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

/**
* Represents the current authentication state between the device and the Bluedot Point API back-end.
*/
typedef NS_ENUM(NSInteger, BDAuthenticationState)
{
    BDAuthenticationStateNotAuthenticated,
    BDAuthenticationStateAuthenticating,
    BDAuthenticationStateAuthenticated
} __attribute__((deprecated("First deprecated in 15.4.0 - This will be removed in future version")));

/**
* Returns a human-readable string form of the given BDAuthenticationState.
*/
NSString *BDStringFromAuthenticationState(BDAuthenticationState state)
__attribute__((deprecated("First deprecated in 15.4.0 - This will be removed in future version")));
