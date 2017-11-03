 
#include "consumer.h"

#include <iostream>

gams::algorithms::BaseAlgorithm *
algorithms::consumerFactory::create (
  const madara::knowledge::KnowledgeMap & /*args*/,
  madara::knowledge::KnowledgeBase * knowledge,
  gams::platforms::BasePlatform * platform,
  gams::variables::Sensors * sensors,
  gams::variables::Self * self,
  gams::variables::Agents * agents)
{
  gams::algorithms::BaseAlgorithm * result (0);
  
  if (knowledge && sensors && platform && self)
  {
    result = new consumer (knowledge, platform, sensors, self);
  }
  else
  {
    madara_logger_ptr_log (gams::loggers::global_logger.get (),
      gams::loggers::LOG_MAJOR,
      "algorithms::consumerFactory::create:" 
      " failed to create due to invalid pointers. " 
      " knowledge=%p, sensors=%p, platform=%p, self=%p, agents=%p\n",
      knowledge, sensors, platform, self, agents);
  }

  /**
   * Note the usage of logger macros with the GAMS global logger. This
   * is highly optimized and is just an integer check if the log level is
   * not high enough to print the message
   **/
  if (result == 0)
  {
    madara_logger_ptr_log (gams::loggers::global_logger.get (),
      gams::loggers::LOG_ERROR,
      "algorithms::consumerFactory::create:" 
      " unknown error creating consumer algorithm\n");
  }
  else
  {
    madara_logger_ptr_log (gams::loggers::global_logger.get (),
      gams::loggers::LOG_MAJOR,
      "algorithms::consumerFactory::create:" 
      " successfully created consumer algorithm\n");
  }

  return result;
}

algorithms::consumer::consumer (
  madara::knowledge::KnowledgeBase * knowledge,
  gams::platforms::BasePlatform * platform,
  gams::variables::Sensors * sensors,
  gams::variables::Self * self,
  gams::variables::Agents * agents)
  : gams::algorithms::BaseAlgorithm (knowledge, platform, sensors, self, agents)
{
  status_.init_vars (*knowledge, "consumer", self->agent.prefix);
  status_.init_variable_values ();
  counter.set_name("counter", *knowledge);
}

algorithms::consumer::~consumer ()
{
}

int
algorithms::consumer::analyze (void)
{
  return 0;
}
      

int
algorithms::consumer::execute (void)
{
  return 0;
}


int
algorithms::consumer::plan (void)
{
	madara_logger_ptr_log (gams::loggers::global_logger.get (), gams::loggers::LOG_MAJOR, "\n ----Now the counter is: %d \n\n", counter.to_integer());
  return 0;
}
