//write file by lisa on 2003.6.27
//update end 
#include <liebiao.h>
inherit F_CLEAN_UP;

int help (object me) ;
mapping places=([	
"bt" : "/d/baituo/dating.c",
"hm" : "/d/heimuya/road1.c",
"bj" : "/d/city2/wenmiao.c",
"tl" : "/d/tianlongsi/damen.c",
"yz" : "/d/city/kedian.c",
"lj" : "/d/lingjiu/damen.c",
"sl" : "/d/shaolin/guangchang1.c",
"wd" : "/d/wudang/sanqingdian.c",
"xy" : "/d/xiaoyao/qingcaop.c",
"xx" : "/d/xingxiu/xxh2.c",
"hhh": "/d/honghua/damen.c",	
"hs" : "/d/huashan/square.c",
"ssl": "/d/shashou/enterance.c",	
"lx" : "/d/lingxiao/shanya.c",	
"xs" : "/d/xueshan/dadian.c",
"kl" : "/d/gaochang/room63.c",
"ny" : "/d/nanyang/nanyang.c",
"tm" : "/d/tangmen/damen.c",	
"tz" : "/d/tiezhang/shanmen.c",	
"qc" : "/d/qingcheng/jianfugong.c",	
"qz" : "/d/quanzhou/zhongxin.c",
"cd" : "/d/city3/guangchang.c",
"hh" : "/d/huanhua/podi.c",	
"ca" : "/d/changan/ca.c",
"dl" : "/d/dali/guangchang.c",
"wu" : "/d/wudujiao/damen.c",
"em" : "/d/emei/guangchang.c",
"mj" : "/d/mingjiao/guangchang1.c",
"gm" : "/d/gumu/rukou.c",
"hsc": "/d/village/sexit.c",
"qzj": "/d/quanzhen/guangchang.c",
"ss" : "/d/songshan/chanyuan.c",
"ts" : "/d/taishan/daizong.c",
"th" : "/d/taohua/haitan.c",
"mz" : "/d/meizhuang/gate.c", 	
"jq" : "/d/jqg/wx.c",   
"sc" : "/d/xiangyang/guangchang.c",
"mw" : "/d/migong/migong1.c",
"bya": "/d/hainan/baiyunan",
"xt" : "/d/xuantian/dongxue",
"shs": "/d/shushan/shanmen",
"tc" : "/d/tongchi/damen",
"xh" : "/d/xuehepai/gate",
"dwm": "/d/wudie/jm",
"cx" : "/d/cxwxm/damen",
"ftyjl" : "/d/feitian/guangchang",
"mf" : VRM_SERVER + "/hades/entry"
]);

int main(object me,string arg)
{
	object room, ob, *obj, env;
	int i;
	if ( !arg )
        {
          return help(me);
        }
	if ( !objectp(env=environment(me)) ) 
		return notify_fail("�����ܻ����ɵ�һƬ���������κζ�����\n");	
	if ( !stringp(places[arg] ) && arg != "home") 
		return notify_fail("��Ҫȥ���\n");	
	if ( me->is_busy() ) 
		return notify_fail("����һ��������û�����,�޷���Խʱ��֮�ţ�\n");	
	if ( me->is_fighting() ) 
		return notify_fail("ս�����޷���Խʱ��֮�ţ�\n");		
	if ( me->is_ghost() ) 
		return notify_fail("��굽���ҷ�,�������˵ģ�\n");	
	if ( !me->query("xy_huiyuan")) 
		return notify_fail("��Ҫȥ���\n");	
	if ( !me->query("xy_huiyuan") && arg == "home" ) 
		return notify_fail("��Ҫȥ���\n");
	if ( !wizardp(me) && env->query("no_fly") ) 
		return notify_fail("�����޷�ʹ�� fly ���д��ͣ�\n");
	if ( me->query_temp("gamble") ) 
		return notify_fail("�㻹��������������߰�!\n");	
	if ( file_size("d/" + "party/" + me->query("party/id") + "/dating.c") <= 0 && arg == "home" ) 
		return notify_fail("�㻹û�м����κΰ��ɡ�\n");	
	//if ( me->query("combat_exp")>50000000 && arg == "new" ) 
	//	return notify_fail("���ڽ������ѵ¸����أ�������ȥ�����������ˡ�\n");
	//if (present("biao yin",me)) 
		//return notify_fail("�����ϴ����������޷���Խʱ��֮�ţ�\n");
	//if ( !wizardp(me) && virtualp(env) ) 
		//return notify_fail("��Ŀǰ���ڸ������ֻ�ܴӸ��������߳�ȥ��\n");
	if ( me->query_condition("killer") ) 
		return notify_fail("ͨ����Ҳ��ʹ��ʱ��֮�ţ�\n");
	
	obj=deep_inventory(me);
	for ( i=0; i<sizeof(obj); i++ )
	{
		if ( obj[i]->id("illicit salt") ) return notify_fail("�����ϴ���˽�Σ��޷���Խʱ��֮�ţ�\n");
		if ( obj[i]->is_character() && !obj[i]->is_corpse() && arg == "new" )
			return notify_fail(obj[i]->name()+"���ܺ���һ��Խʱ��֮�ţ�\n");
	}	
	ob=first_inventory(me);
	while ( ob )
	{
		if ( ob->is_character() && !ob->is_corpse() ) return notify_fail(ob->name()+"���ܺ���һ��Խʱ��֮�ţ�\n");
		ob=next_inventory(ob);
	}
	
	message_vision(YEL+"ֻ��һ��������ᣬ$N����Ӱ�Ѿ������ˡ�\n"+NOR, me);
	
	if ( arg=="home" )
	{
		if ( arg=="home" ) me->move("d/" + "party/" + me->query("party/id") + "/dating.c");
		
	}
	else
	{
		if ( !room=find_object(places[arg]) ) room=load_object(places[arg]);
		
		me->move(room);
	}
	
	message_vision(YEL+"$N����ӰͻȻ������һ������֮�С�\n"+NOR, me);
	
	me->receive_damage("jing", 10);
	me->delete_temp("pended");
	return 1;
}

int help (object me)
{
write(@HELP
ָ���ʽ: fly <�ص�>: ���ָ��������ֱ�ӵ���һЩ���õĵط���
------------------------------------------------------------------
  yz  : ����       hsc : ��ɽ��      dl  : ����       bj  : ����
  hm  : ��ľ��     ca  : ����        hs  : ��ɽ       ny  : ����
  lj  : ���չ�     sl  : ������      wd  : �䵱ɽ     qz  : Ȫ��
  xy  : ��ң��     xx  : ���޺�      xs  : ѩɽ��     kl  : ����
  wu  : �嶾��     tl  : ������      tz  : ���ư�     em  : ����
  cd  : �ɶ�       bt  : ����ɽ      new : ������     gm  : ��Ĺ 
  dwm : ������     mj  : ����        th  : �һ���     ss  : ��ɽ
  jq  : �����     ts  : ̩ɽ        ssl : ɱ��¥     tm  : ����
  lx  : ������     qc  : �����      hhh : �컨��     mz  : ÷ׯ        
  qzj : ȫ���     bya : ������      tc  : ͨ�԰�     mf  : ڤ��
  xt  : ������     mw  : ����ɭ��    xh  : Ѫ����     shs : ��ɽ
  hh  : 佻�����   cx  : ����������  home: ������   sc  : ����
  ftyjl : ����������     
------------------------------------------------------------------
HELP);
return 1;
}
