// baxiandian.c ���ɵ�

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "���ɵ�");
        set("long", @LONG
�����ǰ��ɵ���ڰ˾������������������й����ŵ��������
��Ϊ�����������ա�����Ȩ���Ź��ϡ������������ɹá����ɺ͡���
���ӡ��ܹ��˰��ɡ����з��˺�ľ���㰸���㰸�Ϲ�Ʒ�뱸�����ʮ
����ʢ�� 
LONG
        );  
        
        set("exits", ([
                "northwest" : __DIR__"xilang2",
                "south": __DIR__"xilang1",
        ]));
        set("objects", ([
                __DIR__"npc/qizhicheng" : 1, 
   ]));
        setup();
        replace_program(ROOM);
}

