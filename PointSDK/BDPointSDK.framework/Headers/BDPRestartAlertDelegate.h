//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * @brief Implement this protocol in your UIApplicationDelegate to enable restart prompts to the user, after the App terminates.
 *
 * <p>
 * Implement this protocol in your UIApplicationDelegate to allow an app to be restarted should it be no longer
 * running on the device; the user is given the option to restart the application through a local notification
 * with an action to restart.
 *
 * The title of the banner or alert (depending on user settings on the device) must be provided by the app
 * implementing this protocol.
 * The text on the action button can be set by the application implementing this protocol.
 * </p>
 */
@protocol BDPRestartAlertDelegate <NSObject>

/**
 *  When implementing app restart alert, this method is mandatory.
 *  @return the string to be used in the title of the banner or alert to be used in the local notification to restart the app.
 */
- (NSString *)restartAlertTitle;

@optional
/**
 *  When implementing app restart alert, this method is optional.
 *  @return the string to be used in the text of the action button to be used in the local notification to restart the app.
 */
- (NSString *)restartButtonText;

@end
