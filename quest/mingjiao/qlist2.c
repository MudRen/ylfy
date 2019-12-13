inherit SKILL;
#include <ansi.h>

mapping *quest = ({
        ([      "quest":               "Ô²Õæ",
                "quest_type":           "É±",
                "time":                 1200,
                "score" :               13
        ]),
        ([      "quest":                "¸ßÑå³¬",
                "quest_type":           "É±",
                "time":                 400,
                "score" :               9
        ]),
        ([      "quest":                "ÉñÁú½ÌÀÏÕß",
                "quest_type":           "É±",
                "time":                 400,
                "score" :               9
        ]),
        ([      "quest":               "°×ÒÂÎäÊ¿",
                "quest_type":           "É±",
                "time":                 400,
                "score" :               7
        ]),
        ([      "quest":                "ÓñÖñÕÈ",
                "quest_type":           "Ñ°",
                "time":                 450,
                "score" :               9
        ]),       
        ([      "quest":                "ÄÚÌÃ",
                  "quest_type":           "É¨",
                "time":                 960,
                "score" :               6
        ]),
         ([      "quest":                "×¯·òÈË",
                "quest_type":           "É±",
                "time":                 400,
                "score" :               5
        ]),    
        ([      "quest":                "±øÆ÷¿â",
                "quest_type":           "É¨",
                "time":                 960,
                "score" :               7
        ]),
        ([      "quest":                RED"Ê¥»ðÌÃ"NOR,
                "quest_type":           "É¨",
                "time":                 260,
                "score" :               7
        ]),
        ([      "quest":                "±±Ïá·¿",
                "quest_type":           "É¨",
                "time":                 260,
                "score" :               6
        ]),
        ([      "quest":                "Èñ½ðÆì",
                "quest_type":           "É¨",
                "time":                 260,
                "score" :               6
        ]),
        ([      "quest":                RED"¹âÃ÷¶¥"NOR,
                "quest_type":           "É¨",
                "time":                 260,
                "score" :               6
        ]),
        ([      "quest":                "¿µÇ×Íõ",
                "quest_type":           "É±",
                "time":                 450,
                "score" :               7
        ]),
        ([      "quest":                "ÃÛÌÒ",
                "quest_type":           "Ñ°",
                "time":                 800,
                "score" :               9
        ]),
        ([       "quest":               "Öª¿ÍµÀ³¤",
                "quest_type":           "É±",
                "time":                 300,
                "score" :               6
        ]),

        ([      "quest":                "º£¹«¹«",
                "quest_type":           "É±",
                "time":                 360,
                "score" :               7
        ]),
        ([      "quest":                "»Ò²¼µÀÅÛ",
                "quest_type":           "Ñ°",
                "time":                 450,
                "score" :               9
        ]),  
        ([      "quest":                "ÆëÔª¿­",
                "quest_type":           "É±",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "µÀÍ¯",
                "quest_type":           "É±",
                "time":                 700,
                "score" :               6
        ]),
        ([      "quest":                "ÐìÌì´¨",
                "quest_type":           "É±",
                "time":                 800,
                "score" :               8
        ]),  
        ([      "quest":               "Ò©³ú",
                "quest_type":           "Ñ°",
                "time":                 500,
                "score" :               10
        ]),
        ([      "quest":                "½ðÒ¶",
                "quest_type":           "Ñ°",
                "time":                 450,
                "score" :               6
        ]),
        ([      "quest":                "¸ÖÕÈ",
                "quest_type":           "Ñ°",
                "time":                 400,
                "score" :               7
        ]),  

        ([      "quest":                "Ñø¾«µ¤",
                "quest_type":           "Ñ°",
                "time":                 180,
                "score" :               6
        ]),
        ([      "quest":                "²èÊÒ",
                "quest_type":           "É¨",
                "time":                 200,
                "score" :               6
        ]),
        ([      "quest":                "Ç°Ìü",
                "quest_type":           "É¨",
                "time":                 200,
                "score" :               6
        ]),
        ([      "quest":                "ÌüÌÃ",
                "quest_type":           "É¨",
                "time":                 200,
                "score" :               6
        ]),
        ([      "quest":                "ÑÝÎä³¡",
                "quest_type":           "É¨",
                "time":                 200,
                "score" :               6
        ]),
        ([      "quest":                "µÀµÂ¾­¡¸µÚÊ®ÈýÕÂ¡¹",
                "quest_type":           "Ñ°",
                "time":                 480,
                "score" :               7
        ]),
        ([      "quest":                "µÀµÂ¾­¡¸µÚ°ËÕÂ¡¹",
                "quest_type":           "Ñ°",
                "time":                 480,
                "score" :               7
        ]),
        ([      "quest":                "²¨Ë¹³¤ÅÛ",
                "quest_type":           "Ñ°",
                "time":                 480,
                "score" :               6
        ]),
        ([      "quest":                "°¢À­²®Íäµ¶",
                "quest_type":           "Ñ°",
                "time":                 480,
                "score" :               6
        ]),
        ([      "quest":                "âÎ",
                "quest_type":           "Ñ°",
                "time":                 480,
                "score" :               6
        ]),
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
