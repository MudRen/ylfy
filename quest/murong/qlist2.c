#include <ansi.h>
inherit SKILL;

mapping *quest = ({
        ([       "quest":               "»ô¶¼",
                "quest_type":           "É±",
                "time":                 500,
                "score" :               10
        ]),
        ([      "quest":                "½­°ÙÊ¤",
                "quest_type":           "É±",
                "time":                 500,
                "score" :               6
        ]),
        ([      "quest":                "¿µÇ×Íõ",
                "quest_type":           "É±",
                "time":                 520,
                "score" :               8
        ]),
        ([      "quest":                "ÓñÖñÕÈ",
                "quest_type":           "Ñ°",
                "time":                 550,
                "score" :               9
        ]),       
        ([      "quest":                "É®¹÷",
                "quest_type":           "Ñ°",
                "time":                 550,
                "score" :               9
        ]),  
        ([      "quest":                "ÊÌÎÀ",
                "quest_type":           "É±",
                "time":                 560,
                "score" :               7
        ]),
        ([      "quest":                "ÓÎÁú½£",
                "quest_type":           "Ñ°",
                "time":                 600,
                "score" :               11
        ]),
        ([      "quest":               "Á½ÒÇ½£Æ×<ÏÂ¾í>",
                "quest_type":           "Ñ°",
                "time":                 500,
                "score" :               12
        ]),
        ([       "quest":               "Ì«¼«Ê®ÈýÊÆ",
                "quest_type":           "Ñ°",
                "time":                 600,
                "score" :               15
        ]),
        ([       "quest":               "»ðÕÛ",
                "quest_type":           "Ñ°",
                "time":                 500,
                "score" :               8
        ]),
        ([       "quest":               "Ò©³ú",
                "quest_type":           "Ñ°",
                "time":                 500,
                "score" :               10
        ]),
        ([       "quest":               "×æÇ§Çï",
                "quest_type":           "É±",
                "time":                 600,
                "score" :               7
        ]),
        ([       "quest":               "ÇàÒÂÎäÊ¿",
                "quest_type":           "É±",
                "time":                 500,
                "score" :               7
        ]),
        ([       "quest":               "ºìÒÂÎäÊ¿",
                "quest_type":           "É±",
                "time":                 500,
                "score" :               7
        ]),
        ([       "quest":               "°×ÒÂÎäÊ¿",
                "quest_type":           "É±",
                "time":                 500,
                "score" :               7
        ]),
        ([       "quest":               "ÄïçÙÓñ¶´",
                "quest_type":           "É¨",
                "time":                 200,
                "score" :               6
        ]),
        ([       "quest":               "¾²Òô¸ó",
                "quest_type":           "É¨",
                "time":                 180,
                "score" :               5
        ]),

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
