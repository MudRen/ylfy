inherit SKILL;
#include <ansi.h>

mapping *quest = ({
        ([      "quest":               "¿¾¼¦ÍÈ",
                "quest_type":           "Ñ°",
                "time":                 60,
                "score" :               2
        ]),
        ([      "quest":                "¶Ì½£",
                "quest_type":           "Ñ°",
                "time":                 80,
                "score" :               2
        ]),
        ([      "quest":                "Á÷Ã¥",
                "quest_type":           "É±",
                "time":                 200,
                "score" :               4
        ]),
        ([      "quest":                "Á÷Ã¥Í·",
                "quest_type":           "É±",
                "time":                 420,
                "score" :               10
        ]),
        ([      "quest":                "Ð¡Ã«Â¿",
                "quest_type":           "Ñ°",
                "time":                 420,
                "score" :               6
        ]),
        ([      "quest":                "³¤½£",
                "quest_type":           "Ñ°",
                "time":                 200,
                "score" :               3
        ]),       
        ([      "quest":                "¹âÃ÷µ¶",
                "quest_type":           "Ñ°",
                "time":                 900,
                "score" :               5
        ]), 
        ([      "quest":                "¹âÃ÷½£",
                "quest_type":           "Ñ°",
                "time":                 900,
                "score" :               5
        ]),  
 
        ([      "quest":                "ÍõÐ¡¶þ",
                "quest_type":           "É±",
                "time":                 700,
                "score" :               8
        ]),
        ([      "quest":                "Å£Åï",
                "quest_type":           "É¨",
                "time":                 1000,
                "score" :               5
        ]),
        ([      "quest":                "Å£Æ¤¾Æ´ü",
                "quest_type":           "Ñ°",
                "time":                 130,
                "score" :               2
        ]), 
        ([      "quest":                "ÐÝÏ¢ÊÒ",
                "quest_type":           "É¨",
                "time":                 800,
                "score" :               6
        ]),
        ([      "quest":                "Æ¤±³ÐÄ",
                "quest_type":           "Ñ°",
                "time":                 180,
                "score" :               6
        ]),
        ([      "quest":                "Õ»µÀ",
                "quest_type":           "É¨",
                "time":                 780,
                "score" :               5
        ]),
        ([      "quest":                HIY"ÀÏ»ÆÅ£"NOR,
                "quest_type":           "Ñ°",
                "time":                 900,
                "score" :               4
        ]),  
        ([      "quest":                "ÕÅÔ±Íâ",
                "quest_type":           "É±",
                "time":                 800,
                "score" :               9
        ]),
        ([      "quest":                "ÃÛÌÒ",
                  "quest_type":           "Ñ°",
                "time":                 700,
                "score" :               4
        ]),
       ([      "quest":                "½ð´´Ò©",
                "quest_type":           "Ñ°",
                "time":                 180,
                "score" :               10
        ]),
       ([      "quest":                "³¤½£",
                "quest_type":           "Ñ°",
                "time":                 200,
                "score" :               3
        ]),
        ([      "quest":                "²¼ÒÂ",
                "quest_type":           "Ñ°",
                "time":                 100,
                "score" :               5
        ]),

  });

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

