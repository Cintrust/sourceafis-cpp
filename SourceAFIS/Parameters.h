//
// Created by Junior Trust on 2/22/2020.
//

#ifndef SOURCEAFIS_CPP_PARAMETERS_H
#define SOURCEAFIS_CPP_PARAMETERS_H


#include "Doubles.h"

class Parameters {
    static const int blockSize = 15;
    constexpr static const double dpiTolerance = 5;
    constexpr static const int histogramDepth = 256;
    constexpr static const double clippedContrast = 0.08;
    constexpr  static const double minAbsoluteContrast = 17 / 255.0;
    constexpr static const double minRelativeContrast = 0.34;
    static const int relativeContrastSample = 168568;
    constexpr static const double relativeContrastPercentile = 0.49;
    static const int contrastVoteRadius = 9;
    constexpr static const double contrastVoteMajority = 0.86;
    static const int contrastVoteBorderDistance = 7;
    static const int maskVoteRadius = 7;
    constexpr static const double maskVoteMajority = 0.51;
    static const int maskVoteBorderDistance = 4;
    static const int blockErrorsVoteRadius = 1;
    constexpr static const double blockErrorsVoteMajority = 0.7;
    static const int blockErrorsVoteBorderDistance = 4;
    constexpr  static const double maxEqualizationScaling = 3.99;
    constexpr static const double minEqualizationScaling = 0.25;
    constexpr  static const double minOrientationRadius = 2;
    constexpr static const double maxOrientationRadius = 6;
    static const int orientationSplit = 50;
    static const int orientationsChecked = 20;
    static const int orientationSmoothingRadius = 1;
    static const int parallelSmoothinigResolution = 32;
    static const int parallelSmoothinigRadius = 7;
    constexpr static const double parallelSmoothinigStep = 1.59;
    static const int orthogonalSmoothinigResolution = 11;
    static const int orthogonalSmoothinigRadius = 4;
    constexpr static const double orthogonalSmoothinigStep = 1.11;
    static const int binarizedVoteRadius = 2;
    constexpr  static const double binarizedVoteMajority = 0.61;
    static const int binarizedVoteBorderDistance = 17;
    static const int innerMaskBorderDistance = 14;
    constexpr static const double maskDisplacement = 10.06;
    static const int minutiaCloudRadius = 20;
    static const int maxCloudSize = 4;
    static const int maxMinutiae = 100;
    static const int sortByNeighbor = 5;
    static const int edgeTableRange = 490;
    static const int edgeTableNeighbors = 9;
    static const int thinningIterations = 26;
    static const int maxPoreArm = 41;
    static const int shortestJoinedEnding = 7;
    static const int maxRuptureSize = 5;
    static const int maxGapSize = 20;
    static const int gapAngleOffset = 22;
    static const int toleratedGapOverlap = 2;
    static const int minTailLength = 21;
    static const int minFragmentLength = 22;
    static const int maxDistanceError = 13;
    constexpr static const double maxAngleError = Doubles::toRadians(10);
    constexpr static const double maxGapAngle = Doubles::toRadians(10);
    static const int ridgeDirectionSample = 21;
    static const int ridgeDirectionSkip = 1;
    static const int maxTriedRoots = 70;
    static const int minRootEdgeLength = 58;
    static const int maxRootEdgeLookups = 1633;
    static const int minSupportingEdges = 1;
    constexpr static const double distanceErrorFlatness = 0.69;
    constexpr static const double angleErrorFlatness = 0.27;
    constexpr static const double pairCountScore = 0.032;
    constexpr static const double pairFractionScore = 8.98;
    constexpr static const double correctTypeScore = 0.629;
    constexpr static const double supportedCountScore = 0.193;
    constexpr static const double edgeCountScore = 0.265;
    constexpr static const double distanceAccuracyScore = 9.9;
    constexpr  static const double angleAccuracyScore = 2.79;
    constexpr static const double thresholdMaxFMR = 8.48;
    constexpr static const double thresholdFMR2 = 11.12;
    constexpr static const double thresholdFMR10 = 14.15;
    constexpr static const double thresholdFMR100 = 18.22;
    constexpr static const double thresholdFMR1000 = 22.39;
    constexpr static const double thresholdFMR10_000 = 27.24;
    constexpr static const double thresholdFMR100_000 = 32.01;
};


#endif //SOURCEAFIS_CPP_PARAMETERS_H
