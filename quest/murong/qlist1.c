#include <ansi.h>
inherit SKILL;

mapping *quest = ({
        ([      "quest":               "ÕıŒÂ",
                "quest_type":           "…±",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":                "≥§Ω£",
                "quest_type":           "—∞",
                "time":                 200,
                "score" :               3
        ]),
        ([      "quest":                "∞¢◊œ",
                "quest_type":           "…±",
                "time":                 400,
                "score" :               5
        ]), 
        ([      "quest":                "–«Àﬁ≈…Ó‡ ÷",
                "quest_type":           "…±",
                "time":                 420,
                "score" :               8
        ]),
        ([      "quest":                "≤º“¬",
                "quest_type":           "—∞",
                "time":                 100,
                "score" :               5
        ]),
        ([      "quest":                "ª®∑ ∑ø",
                "quest_type":           "…®",
                "time":                 200,
                "score" :               6
        ]),
        ([      "quest":                "≤ÿæ≠∏Û",
                "quest_type":           "…®",
                "time":                 200,
                "score" :               3
        ]), 
        ([      "quest":                "Œ§¥∫∑º",
                "quest_type":           "…±",
                "time":                 420,
                "score" :               6
        ]),
        ([      "quest":                "Ã˙º◊",
                "quest_type":           "—∞",
                "time":                 200,
                "score" :               6
        ]),       
        ([      "quest":                "∏÷’»",
                "quest_type":           "—∞",
                "time":                 400,
                "score" :               7
        ]),  
        ([      "quest":                "∫Ï…’π∑»‚",
                "quest_type":           "—∞",
                "time":                 200,
                "score" :               4
        ]),
        ([      "quest":                "¡˜√•Õ∑",
                "quest_type":           "…±",
                "time":                 350,
                "score" :               6
        ]),
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

