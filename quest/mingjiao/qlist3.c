inherit SKILL;
#include <ansi.h>

mapping *quest = ({
        ([       "quest":               "ŷ����",
                "quest_type":           "ɱ",
                "time":                 700,
                "score" :               12
        ]),
        ([      "quest":                "ŷ����",
                "quest_type":           "ɱ",
                "time":                 560,
                "score" :               20
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 550,
                "score" :               11
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 550,
                "score" :               11
        ]),
        ([      "quest":                HIG "����" NOR,
                "quest_type":           "Ѱ",
                "time":                 900,
                "score" :               18
        ]),
        ([      "quest":                RED"Բ�����ͷ"NOR,
                "quest_type":           "Ѱ",
                "time":                 900,
                "score" :               18
        ]),
        ([      "quest":                "���᷿",
                  "quest_type":           "ɨ",
                "time":                 300,
                "score" :               11
        ]),
        ([      "quest":                "��ɽ��",
                "quest_type":           "ɨ",
                "time":                 340,
                "score" :               11
        ]),
        ([      "quest":               RED"������"NOR,
                "quest_type":           "ɨ",
                "time":                 260,
                "score" :               12
        ]),
        ([      "quest":                "��������",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               9
        ]),
        ([      "quest":                "����ɢ",
                "quest_type":           "Ѱ",
                "time":                 1200,
                "score" :               12
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 700,
                "score" :               12
        ]),
        ([      "quest":                "�������",
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               14
        ]),
        ([      "quest":                "ҹ����",
                "quest_type":           "Ѱ",
                "time":                 1200,
                "score" :               11
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               12
        ]),
        ([      "quest":                "��������",
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               12
        ]),
        ([      "quest":                "�߸���",
                "quest_type":           "ɱ",
                "time":                 400,
                "score" :               6
        ]),
        ([      "quest":                "ժ����",
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               17
        ]),
        ([      "quest":                "ʨ����",
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               15
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               20
        ]),
        ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "time":                 1200,
                "score" :               11
        ]),
        ([      "quest":                HIW"��������"NOR,
                "quest_type":           "Ѱ",
                "time":                 1200,
                "score" :               11
        ]),
        ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "time":                 1200,
                "score" :               11
        ]),
        ([      "quest":                "���չ���",
                "quest_type":           "Ѱ",
                "time":                 1200,
                "score" :               11
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               12
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               15
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɨ",
                "time":                 340,
                "score" :               11
        ]),
        ([      "quest":                "��ľ��",
                "quest_type":           "ɨ",
                "time":                 340,
                "score" :               11
        ]),
        ([      "quest":                "��ˮ��",
                "quest_type":           "ɨ",
                "time":                 340,
                "score" :               11
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɨ",
                "time":                 340,
                "score" :               11
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɨ",
                "time":                 340,
                "score" :               11
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɨ",
                "time":                 340,
                "score" :               11
        ]),
        ([      "quest":                "�ڹھ���",
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               15
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 900,
                "score" :               10
        ]),
        ([      "quest":                "³�н�",
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               14
        ]),
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
