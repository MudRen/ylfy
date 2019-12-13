#include <ansi.h>
inherit SKILL;
mapping *quest = ({
        ([      "quest":		"ÀÔ≤ª∂˛",               
                "quest_type":           "…±",
                "time":  		900,
               "score"	:		10
        ]),
        ([      "quest":                "≈÷Õ∑Õ”",
                "quest_type":           "…±",
                "time":                 900,
                "score" :               10
        ]),
         ([      "quest":                "—∆∆Õ",
                "quest_type":           "…±",
                "time":                 900,
                "score" :               10
        ]),
        ([      "quest":                "Ù√ÕÚº“",
                "quest_type":           "…±",
                "time":                 900,
                "score" :               10
        ]),
        ([      "quest":                "¿Óƒ™≥Ó",
               "quest_type":           "…±",
                "time":                 900,
               "score" :               10
        ]),       
         ([      "quest":                "Ã˙ ÷’∆",
                "quest_type":           "—∞",
                "time":                 800,
                "score" :               8
        ]),  
        ([      "quest":                GRN"”Ò÷Ò∞Ù"NOR,
                "quest_type":           "—∞",
                "time":                 800,
                "score" :               6
        ]),
        ([      "quest":                "ªÙ∂º",
               "quest_type":           "…±",
                "time":                 700,
                "score" :               10
        ]),
});

mapping query_quest()

{
        return quest[random(sizeof(quest))];
}

