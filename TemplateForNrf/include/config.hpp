#ifndef CONFIG_HPP
#define CONFIG_HPP

#define SENDER

#ifdef SENDER
#define CE_PIN 9
#define CSN_PIN 10
#endif

#ifndef SENDER
#define CE_PIN 9
#define CSN_PIN 10
#endif

#endif
