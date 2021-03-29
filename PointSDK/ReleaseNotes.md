PointSDK v15.5.0 (62)
# SDK Version 15.5.0

**Enhancements** 
- Notification permission needs to be requested explicitly by app
- SDK will no longer request the notification permission after the SDK is initialized. The App will have to request the user to give the notification permission before starting Geo-triggering if it wants to display the message, URL action or the app restart notification to be displayed. More details [here](https://docs.bluedot.io/ios-sdk/migration-guide/ios-migration-guide-from-previous-versions-to-point-sdk-v15-5-0/).
