#include <ansi.h>
inherit SKILL;

mapping *quest = ({
        ([       "quest":               "¿¾¼¦ÍÈ",
                "quest_type":           "Ñ°",
                "time":                 60,
                "score" :               2
        ]),
        ([      "quest":                "Öñ½£",
                "quest_type":           "Ñ°",
                "time":                 80,
                "score" :               2
        ]),
        ([      "quest":                "ÐüÑÂ",
                "quest_type":           "É¨",
                "time":                 100,
                "score" :               4
        ]),
        ([      "quest":                "¹ÅÄ¹",
                "quest_type":           "É¨",
                "time":                 100,
                "score" :               5
        ]),
        ([      "quest":                "µØÆ¦",
                "quest_type":           "É±",
                "time":                 200,
                "score" :               4
        ]),
        ([      "quest":                "Ìú¼×",
                  "quest_type":           "Ñ°",
                "time":                 420,
                "score" :               10
        ]),
        ([      "quest":                "³¤½£",
                "quest_type":           "Ñ°",
                "time":                 120,
                "score" :               3
        ]),       
        ([      "quest":                "¸Öµ¶",
                "quest_type":           "Ñ°",
                "time":                 200,
                "score" :               2
        ]),  
        ([      "quest":                "¹ûÔ°",
                  "quest_type":           "É¨",
                "time":                 700,
                "score" :               8
        ]),
        ([      "quest":                "Ð¡Ã«Â¿",
                "quest_type":           "Ñ°",
                "time":                 600,
                "score" :               10
        ]),
        ([      "quest":                "Å£Æ¤¾Æ´ü",
                "quest_type":           "Ñ°",
                "time":                 130,
                "score" :               2
        ]), 
        ([      "quest":                "°ü×Ó",
                "quest_type":           "Ñ°",
                "time":                 120,
                "score" :               2
        ]),
         ([      "quest":               "Æ¤±³ÐÄ",
                "quest_type":           "Ñ°",
                "time":                 180,
                "score" :               5
        ]),
        ([      "quest":                "¾ÉÖñÆ¬",
                "quest_type":           "Ñ°",
                "time":                 180,
                "score" :               5
        ]),
        ([      "quest":                "Ìú´¸",
                "quest_type":           "Ñ°",
                "time":                 180,
                "score" :               5
        ]),        
        ([      "quest":                "½ð´´Ò©",
                "quest_type":           "Ñ°",
                "time":                 180,
                "score" :               10
        ]),
        ([      "quest":                "Ñø¾«µ¤",
                "quest_type":           "Ñ°",
                "time":                 180,
                "score" :               6
        ]),
        ([      "quest":                "Ðå»¨Õë",
                "quest_type":           "Ñ°",
                "time":                 180,
                "score" :               6
        ]),
        ([      "quest":                "È­Æ××Ü¾÷",
                "quest_type":           "Ñ°",
                "time":                 200,
                "score" :               6
        ]),
        ([      "quest":                "ÍÃÈâ",
                "quest_type":           "Ñ°",
                "time":                 300,
                "score" :               6       
        ]),
        ([      "quest":                "Ç°Ìü",
                "quest_type":           "É¨",
                "time":                 300,
                "score" :               6
        ]),
    
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}


