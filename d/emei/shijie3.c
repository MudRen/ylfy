// shijie3.c ʯ��3
// create by host dec,12

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����������һ���ü�ʵʯ���̳ɵĿ��ʯ�ף����߽���ʯ����ƾ�����ͣ�
ңң���������Ҿ�����ѭʯ�׶��ϣ��ٲ��ɴ�ص���ӳ�У����ߵ�̫������
��������ԣ�������˵������������Ŀ��
LONG
	);
        set("outdoors", "emei");
	set("exits", ([
                "southup" : __DIR__"baizhangyan",
                "northdown":__DIR__"lianhua"
      	]));
	setup();
}

