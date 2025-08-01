#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Config *readConfig() {
  Config *config = malloc(sizeof(Config));
  char filename[256];
  strcat(strcpy(filename, getenv("HOME")), RCFILE);
  FILE *configFile = fopen(filename, "r");
  if (configFile == NULL) {
    printf("%s\n", "Failed to open the config file");
    exit(1);
  }
  char line[64];
  while (fgets(line, 64, configFile) != NULL) {
    char name[32], value[32];
    sscanf(line, "%s %s", name, value);
    if (strcmp(name, "location_x") == 0) {
      config->location_x = atoi(value);
    } else if (strcmp(name, "location_y") == 0) {
      config->location_y = atoi(value);
    } else if (strcmp(name, "map_width") == 0) {
      config->map_width = atoi(value);
    } else if (strcmp(name, "black") == 0) {
      if (strcmp(value, "true") == 0) {
        config->black = true;
      } else {
        config->black = false;
      }
    } else if (strcmp(name, "update_interval") == 0) {
      config->update_interval = atoi(value);
    }
  }

  return config;
}
