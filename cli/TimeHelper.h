//
// Created by xixie on 2019/8/21.
//

#ifndef CPPCHECK_TIME_H
#define CPPCHECK_TIME_H

#include <time.h>
namespace cppcheck{

#define CLOCKS_PER_SEC ((clock_t)1000)
#define CLOCKS_PER_MIN ((clock_t)60000)
#define CLOCKS_PER_HOUR ((clock_t)3600000)

struct TimeDetail{
    long hour;
    long minute;
    long sec;
};


TimeDetail GetElapseTime(clock_t startTime, clock_t endTime)
{
    TimeDetail stTimeDetail;
    long  lElapseHourTime = (endTime - startTime) / CLOCKS_PER_HOUR;
    long  lElapseMinuteTime = ( (endTime - startTime) - lElapseHourTime * CLOCKS_PER_HOUR)/ CLOCKS_PER_MIN;
    long  lElapseSecTime =  ((endTime - startTime) - lElapseHourTime * CLOCKS_PER_HOUR - lElapseMinuteTime * CLOCKS_PER_MIN) / CLOCKS_PER_SEC;
    stTimeDetail.hour = lElapseHourTime;
    stTimeDetail.minute = lElapseMinuteTime;
    stTimeDetail.sec = lElapseSecTime;

    return stTimeDetail;
}

}




#endif //CPPCHECK_TIME_H
