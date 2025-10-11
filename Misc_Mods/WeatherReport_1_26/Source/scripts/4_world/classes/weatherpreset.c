class WeatherPreset
{
    int report;
    string name;

    float transition_min;
    float transition_max;

    float duration_min;
    float duration_max;

    float overcast_min;
    float overcast_max;

    float fog_min;
    float fog_max;
    float fog_bias;
    float fog_height;
    float fog_distance_min;

    float windSpeed_min;
    float windSpeed_max;

    float windDirection_min;
    float windDirection_max;

    float rain_min;
    float rain_max;

    float snowfall_min;
    float snowfall_max;

    bool storm;
    float thunder_timeout;
}