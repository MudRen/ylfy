#include <ansi.h>

inherit SKILL;

mapping *quest = ({
        ([      "quest":                "“¸÷æ∆Ω",               
                "quest_type":           "…±",
                "time":                 1200,
                "score" :               12
        ]),
        ([      "quest":                "’‘÷ææ¥",               
                "quest_type":           "…±",
                "time":                 1200,
                "score" :               12
        ]),
        ([      "quest":                "¿Ó÷æ≥£",               
                "quest_type":           "…±",
                "time":                 1200,
                "score" :               10
        ]),
        ([      "quest":                "√∑Ω£",               
                "quest_type":           "…±",
                "time":                 1200,
                "score" :               13
        ]),
        ([      "quest":                "≈Ì”®”Ò",               
                "quest_type":           "…±",
                "time":                 1200,
                "score" :               14
        ]),

        ([      "quest":                "œÙ∏’",
                "quest_type":           "…±",
                "time":                 1200,
                "score" :               14
        ]),
        ([      "quest":                "¬Ì≥¨–À",
                "quest_type":           "…±",
                "time":                 1000,
                "score" :               12
        ]),
        ([      "quest":                "œÙ»Õ",
                "quest_type":           "…±",
                "time":                 1200,
                "score" :               12
        ]),  
        ([      "quest":                "ÀŒ‘∂«≈",
                "quest_type":           "…±",
                "time":                 1200,
                "score" :               14
        ]),
        ([      "quest":                "¡Ó∫¸≥Â",
                "quest_type":           "…±",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "∂Œ”˛",
                "quest_type":           "…±",
                "time":                 700,
                "score" :               10
        ]),

        ([      "quest":                HIC"«Ÿ “"NOR,
                "quest_type":           "…®",
                "time":                 300,
                "score" :               12
        ]),
        ([      "quest":                HIC" Ø “"NOR,
                "quest_type":           "…®",
                "time":                 400,
                "score" :               13
        ]),
        ([      "quest":                HIG"∫ÛÃ√"NOR,
                "quest_type":           "…®",
                "time":                 400,
                "score" :               9
        ]),
        ([      "quest":                HIC"–›œ¢ “"NOR,
                "quest_type":           "…®",
                "time":                 400,
                "score" :               10
        ]),
        ([      "quest":                HIC"Ω£ “"NOR,
                "quest_type":           "…®",
                "time":                 500,
                "score" :               9
        ]),
        ([      "quest":                "¥Ô∂˚∞Õ",
                "quest_type":           "…±",
                "time":                 900,
                "score" :               11
        ]),
        ([       "quest":               "∂Œ—”«Ï",
                "quest_type":           "…±",
                "time":                 560,
                "score" :               11
        ]),
        ([       "quest":               "≤®Àπ≥§≈€",
                "quest_type":           "—∞",
                "time":                 500,
                "score" :               10
        ]),
        ([       "quest":               "∂∑≈Ò",
                "quest_type":           "—∞",
                "time":                 800,
                "score" :               8
        ]),
        ([       "quest":               "‚Œ",
                "quest_type":           "—∞",
                "time":                 900,
                "score" :               13
        ]),           
        ([       "quest":               "∞¢¿≠≤ÆÕ‰µ∂",
                "quest_type":           "—∞",
                "time":                 900,
                "score" :               14
        ]),

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
