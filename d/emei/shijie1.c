// shijie1.c ʯ��
// create by host dec,12

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����һ���ü�ʵʯ���̳ɵĿ��ʯ�ף����߽���ʯ����ƾ�����ͣ�̧ͷ��
Լ�ɼ������������е������壬ѭʯ�׶��ϣ���Ȼǰ�У�������ˮ���ȣ�������
��������
LONG
	);
        set("outdoors", "emei");
	set("exits", ([
		"southup" : __DIR__"shijie2",
                "east": __DIR__"basipan3"
      	]));
	setup();
}

