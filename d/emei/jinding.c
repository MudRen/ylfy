// Room: /d/emei/jinding.c ������ ��
// create by host dec,15
inherit ROOM;


void create()
{
	set("short", "��");
	set("long", @LONG
����ʱ�����ϵľ������𶥡������Ͼ����Ĺۺ��£�վ�����������ķ���
ֻ������Ư��������������ɽ�����ܣ��������Σ��������󡣴������Ҷ�
�ϣ�������෴����Ͷ���������ϳ�����һ���޴�Ĳ�ɫ�⻷���⻷�п���
��ɽ����ͬ���еĵ��죬��ɫʮ�ֵ�׳�ۡ��������������˶������ı�
ɲ�������֡��������������Ƕ��ҵĲؾ��󡸻����֡���
LONG
	);
        set("outdoors", "emei");
	set("exits", ([
                 "northdown": __DIR__"baizhangyan",
                 "west": __DIR__"miaomen",
                 "southup" : __DIR__"duguangtai",
	]));
	set("objects",([
	]));

	setup();
        call_other("/clone/board/emei_b","???");
}
