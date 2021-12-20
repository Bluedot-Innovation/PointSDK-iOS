// swift-tools-version:5.5.0

import PackageDescription

let package = Package(
    name: "PointSDK",
    platforms: [
        .iOS(.v10)
    ],
    products: [
        .library(
            name: "PointSDK",
            targets: ["PointSDK"]
        )
    ],
    targets:[
        .binaryTarget(
            name: "PointSDK",
            path: "PointSDK/BDPointSDK.xcframework"
        )
    ]
)
