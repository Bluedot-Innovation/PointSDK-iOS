//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

/**
* Represents the current initialization state between the device and the Bluedot Point API back-end.
*/
typedef NS_ENUM(NSInteger, BDInitializationState)
{
    BDInitializationStateNotInitialized,
    BDInitializationStateInitializing,
    BDInitializationStateInitialized
};

/**
* Returns a human-readable string form of the given BDInitializationState.
*/
NSString *BDStringFromInitializationState(BDInitializationState state);
