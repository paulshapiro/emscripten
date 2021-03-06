
// Extra libc helper functions

char *tzname[2];

void* _get_tzname() {
  return (void*)tzname;
}

int daylight;

int* _get_daylight() {
  return &daylight;
}

long timezone;

long* _get_timezone() {
  return &timezone;
}

char** environ;

char*** _get_environ() {
  return &environ;
}

// Call JS to build the default environment.

extern void __buildEnvironment(void*);

// TODO: this needs very high priority, so user ctors that use environ do not happen first
__attribute__((constructor))
void __emscripten_environ_constructor(void) {
  __buildEnvironment((void*)&environ);
}

