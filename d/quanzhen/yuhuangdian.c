// yuhuangdian.c ��ʵ�

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "��ʵ�");
        set("long", @LONG
��������ʵ���й����ŵ���ģ������ʴ�ۣ������й������
���е�����������������硣�������������з��˺�ľ���㰸��
�㰸�Ϲ�Ʒ�뱸�����ʮ����ʢ��
LONG
        );
       

        set("exits", ([
                "north" : __DIR__"sanqingdian",
                "south" : __DIR__"guangchang",
        ]));
        set("objects", ([
                __DIR__"npc/lizhichang" : 1, 
   ]));

        setup();
        replace_program(ROOM);
}


