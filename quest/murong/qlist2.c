#include <ansi.h>
inherit SKILL;

mapping *quest = ({
        ([       "quest":               "����",
                "quest_type":           "ɱ",
                "time":                 500,
                "score" :               10
        ]),
        ([      "quest":                "����ʤ",
                "quest_type":           "ɱ",
                "time":                 500,
                "score" :               6
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 520,
                "score" :               8
        ]),
        ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "time":                 550,
                "score" :               9
        ]),       
        ([      "quest":                "ɮ��",
                "quest_type":           "Ѱ",
                "time":                 550,
                "score" :               9
        ]),  
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 560,
                "score" :               7
        ]),
        ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               11
        ]),
        ([      "quest":               "���ǽ���<�¾�>",
                "quest_type":           "Ѱ",
                "time":                 500,
                "score" :               12
        ]),
        ([       "quest":               "̫��ʮ����",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               15
        ]),
        ([       "quest":               "����",
                "quest_type":           "Ѱ",
                "time":                 500,
                "score" :               8
        ]),
        ([       "quest":               "ҩ��",
                "quest_type":           "Ѱ",
                "time":                 500,
                "score" :               10
        ]),
        ([       "quest":               "��ǧ��",
                "quest_type":           "ɱ",
                "time":                 600,
                "score" :               7
        ]),
        ([       "quest":               "������ʿ",
                "quest_type":           "ɱ",
                "time":                 500,
                "score" :               7
        ]),
        ([       "quest":               "������ʿ",
                "quest_type":           "ɱ",
                "time":                 500,
                "score" :               7
        ]),
        ([       "quest":               "������ʿ",
                "quest_type":           "ɱ",
                "time":                 500,
                "score" :               7
        ]),
        ([       "quest":               "������",
                "quest_type":           "ɨ",
                "time":                 200,
                "score" :               6
        ]),
        ([       "quest":               "������",
                "quest_type":           "ɨ",
                "time":                 180,
                "score" :               5
        ]),

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
