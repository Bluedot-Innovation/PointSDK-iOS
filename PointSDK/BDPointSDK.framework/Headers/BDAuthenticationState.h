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
};

/**
* Returns a human-readable string form of the given BDAuthenticationState.
*/
NSString *BDStringFromAuthenticationState(BDAuthenticationState state);
