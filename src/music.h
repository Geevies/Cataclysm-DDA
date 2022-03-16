#include <map>
#include <string>

#include "enum_conversions.h"
#include "enum_traits.h"

namespace music
{
enum music_id {
    mp3,
    instrument,
    sound,
    title
};

extern std::map<music_id, bool> music_id_list;

bool is_active_music_id( music_id data );
music_id get_music_id();
std::string get_music_id_string();
void activate_music_id( music_id data );
void activate_music_id( std::string data );
void deactivate_music_id( music_id data );
void deactivate_music_id( std::string data );
void deactivate_music_id_all();
} // namespace music

// Use enum_traits for generic iteration over music_id, and string (de-)serialization.
// Use io::string_to_enum<music_id>( music_id ) to convert a string to music_id.
template<>
struct enum_traits<music::music_id> {
    static constexpr music::music_id last = music::music_id::title;
};
