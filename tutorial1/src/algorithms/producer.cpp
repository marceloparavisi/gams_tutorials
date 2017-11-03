 
#include "producer.h"

#include <iostream>

gams::algorithms::BaseAlgorithm *
algorithms::producerFactory::create (
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
    result = new producer (knowledge, platform, sensors, self);
  }
  else
  {
    madara_logger_ptr_log (gams::loggers::global_logger.get (),
      gams::loggers::LOG_MAJOR,
      "algorithms::producerFactory::create:" 
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
      "algorithms::producerFactory::create:" 
      " unknown error creating producer algorithm\n");
  }
  else
  {
    madara_logger_ptr_log (gams::loggers::global_logger.get (),
      gams::loggers::LOG_MAJOR,
      "algorithms::producerFactory::create:" 
      " successfully created producer algorithm\n");
  }

  return result;
}

algorithms::producer::producer (
  madara::knowledge::KnowledgeBase * knowledge,
  gams::platforms::BasePlatform * platform,
  gams::variables::Sensors * sensors,
  gams::variables::Self * self,
  gams::variables::Agents * agents)
  : gams::algorithms::BaseAlgorithm (knowledge, platform, sensors, self, agents)
{
  status_.init_vars (*knowledge, "producer", self->agent.prefix);
  status_.init_variable_values ();
  counter.set_name("counter", *knowledge);
}

algorithms::producer::~producer ()
{
}

int
algorithms::producer::analyze (void)
{
  return 0;
}
      

int
algorithms::producer::execute (void)
{
  return 0;
}


int
algorithms::producer::plan (void)
{
	counter += 1;
	madara_logger_ptr_log (gams::loggers::global_logger.get (), gams::loggers::LOG_MAJOR, "\n ----Incrementing the to counter: %d \n\n", counter.to_integer());

  return 0;
}
