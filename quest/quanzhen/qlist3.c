#include <ansi.h>

inherit SKILL;

mapping *quest = ({
        ([      "quest":                "ŷ����",
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               20
        ]),
        ([      "quest":                "�Ħ��",
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               20
        ]),
        ([      "quest":                "��Ī��",
                "quest_type":           "ɱ",
                "time":                 1000,
                "score" :               16
        ]),
        ([      "quest":                "ҹ����",
                "quest_type":           "Ѱ",
                "time":                 1200,
                "score" :               15
        ]),
        ([      "quest":                HIG"����"NOR,
                "quest_type":           "Ѱ",
                "time":                 1200,
                "score" :               15
        ]),
        ([      "quest":                "�Ϲ���",
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               18
        ]),
        ([      "quest":                "ʨ����",
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               20
        ]),
        ([      "quest":                "�ڰ���",
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               20
        ]),
        ([      "quest":                "�ɺ�ҩ",
                "quest_type":           "Ѱ",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "�����޶������ϲ᡽��",
                "quest_type":           "Ѱ",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "���¾����¾�",
                "quest_type":           "Ѱ",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "�һ���",
                "quest_type":           "Ѱ",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "���",
                "quest_type":           "Ѱ",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "�鰲ͨ",
                "quest_type":           "ɱ",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "��������",
                "quest_type":           "ɱ",
                "time":                 700,
                "score" :               10
        ]),

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

