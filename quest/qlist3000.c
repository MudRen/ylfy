#include <ansi.h>
mapping *quest = ({
     ([      "quest":                "�׽��ѧƪ",
                "diff":                 3,
        ]),
        ([      "quest":                "��ݮ",
                "diff":                 2,
        ]),
        ([      "quest":                "ָ��",
                "diff":                 1,
        ]),
     ([      "quest":                "���ܹ�",
                "diff":                 2,
        ]),
     ([      "quest":                "����",
                "diff":                 2,
        ]),
     ([      "quest":                "��",
                "diff":                 2,
        ]),
     ([      "quest":                HIY "������" NOR,
                "diff":                 5,
        ]),
        ([      "quest":                "����ƴ�",
                "diff":                 2,
        ]),
        ([      "quest":                "��Ѽ",
                "diff":                 2,
        ]),
        ([      "quest":                "�鲼��",
                "diff":                 1,
        ]),
});
mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
