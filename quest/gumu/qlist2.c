#include <ansi.h>
inherit SKILL;
mapping *quest = ({
        ([      "quest":		"�ﲻ��",               
                "quest_type":           "ɱ",
                "time":  		900,
               "score"	:		10
        ]),
        ([      "quest":                "��ͷ��",
                "quest_type":           "ɱ",
                "time":                 900,
                "score" :               10
        ]),
         ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 900,
                "score" :               10
        ]),
        ([      "quest":                "�����",
                "quest_type":           "ɱ",
                "time":                 900,
                "score" :               10
        ]),
        ([      "quest":                "��Ī��",
               "quest_type":           "ɱ",
                "time":                 900,
               "score" :               10
        ]),       
         ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "time":                 800,
                "score" :               8
        ]),  
        ([      "quest":                GRN"�����"NOR,
                "quest_type":           "Ѱ",
                "time":                 800,
                "score" :               6
        ]),
        ([      "quest":                "����",
               "quest_type":           "ɱ",
                "time":                 700,
                "score" :               10
        ]),
});

mapping query_quest()

{
        return quest[random(sizeof(quest))];
}

