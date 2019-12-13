#include <ansi.h>
inherit SKILL;

mapping *quest = ({
        ([      "quest":               "ÕıŒÂ",
                "quest_type":           "…±",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":               "∫Œ ¶Œ“",
                "quest_type":           "…±",
                "time":                 500,
                "score" :               10
        ]),
        ([      "quest":                "Œ§¥∫∑º",
                "quest_type":           "…±",
                "time":                 420,
                "score" :               6
        ]),
        ([       "quest":               "ª’€",
                "quest_type":           "—∞",
                "time":                 500,
                "score" :               8
        ]),
        ([      "quest":                "—√“€",
                "quest_type":           "…±",
                "time":                 350,
                "score" :               6
        ]),
        ([      "quest":                "ª“≤ºµ¿≈€",
                "quest_type":           "—∞",
                "time":                 450,
                "score" :               9
        ]),  
        ([      "quest":               "«Â–ƒ…¢",
                "quest_type":           "—∞",
                "time":                 500,
                "score" :               12
        ]),
        ([      "quest":                "√…∫π“©",
                "quest_type":           "—∞",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "∞¢¿≠ƒæ∫±",
                "quest_type":           "…±",
                "time":                 420,
                "score" :               8
        ]),
        ([      "quest":                "Ã˙º◊",
                "quest_type":           "—∞",
                "time":                 300,
                "score" :               6
        ]), 

        ([      "quest":                "Ω≠∞Ÿ §",
                "quest_type":           "…±",
                "time":                 420,
                "score" :               6
        ]),
        ([      "quest":                "¿À»À",
                "quest_type":           "…±",
                "time":                 520,
                "score" :               8
        ]),
        ([      "quest":                "ŒË…ﬂ»À",
                "quest_type":           "…±",
                "time":                 520,
                "score" :               8
        ]),
        ([      "quest":                "ƒæ”„È≥",
                "quest_type":           "—∞",
                "time":                 400,
                "score" :               6
        ]),    
        ([      "quest":                "Ω“∂",
                "quest_type":           "—∞",
                "time":                 550,
                "score" :               10
        ]),        
        ([      "quest":                YEL"Õ≠∞Â"NOR,
                "quest_type":           "—∞",
                "time":                 200,
                "score" :               6
        ]),      
        ([      "quest":                "≤Ë “",
                "quest_type":           "…®",
                "time":                 200,
                "score" :               7
        ]),  
        ([      "quest":                "“Â∆¯Ã√",
                "quest_type":           "…®",
                "time":                 200,
                "score" :               7
        ]),  
        ([      "quest":                "π∑∆§",
                "quest_type":           "—∞",
                "time":                 200,
                "score" :               5
        ]),
        ([      "quest":                "Ω£øÕ",
                "quest_type":           "…±",
                "time":                 520,
                "score" :               6
        ]),
        ([      "quest":                "¡˜√•Õ∑",
                "quest_type":           "…±",
                "time":                 420,
                "score" :               4
        ]),
        ([      "quest":                "–°Ã´º‡",
                "quest_type":           "…±",
                "time":                 520,
                "score" :               6
        ]),
        ([      "quest":                "¿œ±∆≈",
                "quest_type":           "…±",
                "time":                 520,
                "score" :               6
        ]),
        ([      "quest":                "—æª∑",
                "quest_type":           "…±",
                "time":                 520,
                "score" :               6
        ]),
        ([      "quest":                "Œ‚÷Æ»Ÿ",
                "quest_type":           "…±",
                "time":                 520,
                "score" :               6
        ]),
        ([      "quest":                "¡∑µ§∑ø",
                "quest_type":           "…®",
                "time":                 280,
                "score" :               9
        ]),
        ([      "quest":               "ÀÆ∫¯",
                "quest_type":           "—∞",
                "time":                 480,
                "score" :               6
        ]),
        ([      "quest":                "¬È–¨",
                "quest_type":           "—∞",
                "time":                 500,
                "score" :               7
        ]),
});
mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
