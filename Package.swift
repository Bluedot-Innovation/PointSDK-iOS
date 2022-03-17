// swift-tools-version:5.5.0

import PackageDescription

let package = Package(
    name: "BDPointSDK",
    platforms: [
        .iOS(.v10)
    ],
    products: [
        .library(
            name: "BDPointSDK",
            targets: ["BDPointSDK"]
        )
    ],
    targets:[
        .binaryTarget(
            name: "BDPointSDK",
            path: "PointSDK/BDPointSDK.xcframework"
        )
    ]
)
