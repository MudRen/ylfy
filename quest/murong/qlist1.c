#include <ansi.h>
inherit SKILL;

mapping *quest = ({
        ([      "quest":               "����",
                "quest_type":           "ɱ",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               3
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 400,
                "score" :               5
        ]), 
        ([      "quest":                "����������",
                "quest_type":           "ɱ",
                "time":                 420,
                "score" :               8
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 100,
                "score" :               5
        ]),
        ([      "quest":                "���ʷ�",
                "quest_type":           "ɨ",
                "time":                 200,
                "score" :               6
        ]),
        ([      "quest":                "�ؾ���",
                "quest_type":           "ɨ",
                "time":                 200,
                "score" :               3
        ]), 
        ([      "quest":                "Τ����",
                "quest_type":           "ɱ",
                "time":                 420,
                "score" :               6
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               6
        ]),       
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 400,
                "score" :               7
        ]),  
        ([      "quest":                "���չ���",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               4
        ]),
        ([      "quest":                "��åͷ",
                "quest_type":           "ɱ",
                "time":                 350,
                "score" :               6
        ]),
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

