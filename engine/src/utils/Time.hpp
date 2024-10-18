#pragma once


class Time {
public:
    /**
     * @return the time in milliseconds in unix time. OS dependent implementation.
     */
    static double getTime();
};
