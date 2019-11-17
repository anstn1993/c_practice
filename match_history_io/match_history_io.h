#ifndef MATCH_HISTORY_H
#define MATCH_HISTORY_H

void write_match_history(char* buffer, size_t buffer_size, const char* names[], const int wins[], const int losses[], const float kills[], const float deaths[], const float assists[], size_t count);
void read_match_history(char* buffer);

#endif /* MATCH_HISTORY_H */