// fazai.c 发崽
// By Lgg,1998.10

#include <ansi.h>
inherit NPC;
int pieqian(object me);
int pieshuang(object me);
int do_deal();
int do_turn();
int yesorno();
string cstr(int i);

//全程变量
int sumi,summ;
int thecash;
int m1,m2,m3,i1,i2,i3,j1,j2,j3,k1,k2,k3;

void create()
{
	set_name("发崽", ({ "fa zai", "fa" }));
	set("gender", "男性");
	set("long",
		"这是世界赌王、独闯好来务的发哥。\n"
	);
	set("age", 32);
	set("title",HIW"世界赌王"NOR);
	set("nickname",CYN"赌神"NOR);

	set("immortal",1);

	set("inquiry", ([
		"刘德华"   : "他是我的徒弟。\n",  
		"赌" : "要赌就赌，莫说废话。\n",
	]) );	

	set("book_count",1);

	setup();

	carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
	add_action("do_deal","deal");
	add_action("do_turn","turn");
}

int accept_object(object who, object ob)
{
	object me=this_player();

	if (query("book_count")) {
    	if (ob->query("money_id")) {
		if (ob->query_temp("tmark/押")) {
			message_vision(HIG"发崽诧异地看着$N说：你已经下过注了呀！\n"NOR,who);
		}
		if (ob->value()<100) {
			message_vision(HIR"发崽不屑一顾地看着$N，说道：要下注至少一两银子！\n"NOR,who);
			return 0;
		}
		if (ob->value()>20000) {
			message_vision(HIR"发崽摇了摇头，对$N说道：这里不欢迎孤注一掷，最多下注2两黄金。\n"NOR,who);
			return 0;
		}
		add("book_count",-1);
		thecash = ob->value();
		who->set_temp("tmark/押",1);
		sumi=summ=0;
		i1=i2=i3=m1=m2=m3=j1=j2=j3=k1=k1=k3=0;
		message_vision(HIY"发崽吆喝道：$N下注完成，发牌了。\n"NOR,who);
		i1 = 1+random(13);
		i2 = 1+random(13);
		message("vision",WHT"庄家的牌是:    ？   和   "+cstr(i1)+"\n"NOR,who);
		if (i1>10) j1=10;
		else j1=i1;
		if (i2>10) j2=10;
		else j2=i2;
		sumi = j1 + j2;

		m1 = 1+random(13);
		m2 = 1+random(13);
		message("vision",WHT"\n你的牌是:    "+cstr(m1)+"   和   "+cstr(m2)+"\n"NOR,who);     
		if (m1>10) k1=10;
		else k1=m1;
		if (m2>10) k2=10;
		else k2=m2;
		summ = k1+k2;
		if ((summ == 21) || ((summ==11) && (m1==1 || m2==1)) ) {
			message("vision",HIG"啊！BLACKJACK，你真厉害，该赔你双倍啊！\n"NOR,who);
			remove_call_out("destroying");
        		call_out("destroying", 0, me, ob);
			pieshuang(who);
			set("book_count",1);
		}
		else {
			message("vision",HIW"如果还要牌，请type deal,否则请type turn。\n"NOR,who);
		} 

	        remove_call_out("destroying");
        	call_out("destroying", 0, me, ob);
		return 1;
	}
	} // if (query("book_count"))
	else {
		message_vision("已经有人在发崽对赌了，看来$N得等下波儿了。\n",who);
		return 0;
	}
}

int do_deal()
{
	object me=this_player();
	int m3;

	if (!me->query_temp("tmark/押")) {
		message_vision(MAG"发崽不耐烦地推了$N一把：去去去，注还没下呢，要什么牌啊！\n"NOR,me);
		return 1;
	}
	m3 = 1+random(13);
	message("vision",HIM"你还要一张啊，好吧，给你这张牌:   "+cstr(m3)+"\n"NOR,me);
	if (m3>10) k3=10;
	else k3=m3;
	summ = summ+k3;
	if(m1==1 || m2==1 || m3==1)
		if(summ<12)
			summ=summ+10;

	if (summ>21) {
		message("vision",WHT"发崽笑嘻嘻地说：不好意思，你的牌涨爆了，我又赢了。\n"NOR,me);
	}
	else {
		if (summ==21) {
			message("vision",HIW"发崽面如土色：又是２１点？你真厉害，该赔你双倍啊！\n"NOR,me);
			pieshuang(me);	
		}
		else {
			sumi = yesorno();
			if(i1==1 || i2==1 || i3==1) {
				if(sumi<12)
					sumi=sumi+10;
				if(sumi>21)
					sumi=sumi-10;
			}
	
			if (sumi>21 || sumi<summ) {
				if (sumi>21)
					message("vision",HIY"发崽丧气地说：我的牌"+cstr(i1)+cstr(i2)+cstr(i3)+"涨爆了，赔你！\n"NOR,me);
				else
					message("vision",HIY"发崽气得一把把牌扔在桌上：我是"+cstr(i1)+cstr(i2)+cstr(i3)+"，没你点大。\n"NOR,me);
				pieqian(me);
			}
			else {
			if (sumi == summ) {
				message("vision",HIG"发崽贼兮兮的道：不好意思，我是"+cstr(i1)+cstr(i2)+cstr(i3)+"，同点庄家吃了。\n"NOR,me);
			}
			else {
				message("vision",HIG"发崽笑嘻嘻地说：我的牌是"+cstr(i1)+cstr(i2)+cstr(i3)+"\n"NOR,me);
				message("vision",HIG"发崽满脸遗憾的表情：大家这么熟的朋友了，怎么能赢你的钱呢？\n"NOR,me);
			}
			} 
		}
	}

	me->set_temp("tmark/押",0);
	set("book_count",1);
	return 1;
}

int do_turn()
{
	object me = this_player();
	if (!me->query_temp("tmark/押")) {
		message_vision(HIY"发崽不耐烦地推了$N一把：去去去，注还没下呢，亮什么牌啊！\n"NOR,me);
		return 1;
	}

	summ = summ+k3;
	if(m1==1 || m2==1 || m3==1)
		if(summ<12)
			summ=summ+10;

	sumi = yesorno();
	if(i1==1 || i2==1 || i3==1) {
		if(sumi<12)
			sumi=sumi+10;
		if(sumi>21)
			sumi=sumi-10;
	}
	
	if (sumi>21 || sumi<summ) {
		if (sumi>21)
			message("vision",HIY"发崽丧气地说：我的牌"+cstr(i1)+cstr(i2)+cstr(i3)+"涨爆了，赔你！\n"NOR,me);
		else
			message("vision",HIY"发崽气得一把把牌扔在桌上：我是"+cstr(i1)+cstr(i2)+cstr(i3)+"，没你点大。\n"NOR,me);
		pieqian(me);
		}
	else {
		if (sumi == summ) {
			message("vision",HIG"发崽贼兮兮的道：不好意思，我是"+cstr(i1)+cstr(i2)+cstr(i3)+"，同点庄家吃了。\n"NOR,me);
		}
		else {
			message("vision",HIG"发崽笑嘻嘻地说：我的牌是"+cstr(i1)+cstr(i2)+cstr(i3)+"\n"NOR,me);
			message("vision",HIG"发崽满脸遗憾的表情：大家这么熟的朋友了，怎么能赢你的钱呢？\n"NOR,me);
		}
	} 

	me->set_temp("tmark/押",0);
	set("book_count",1);
	return 1;
}

int pieqian(object me)
{
	object ob,ob1;

	if(thecash<10000) {
	ob = new("/clone/money/silver");
	ob->set_amount(thecash/100*2);
	ob->move(me);	
	}
	else {
	ob = new("/clone/money/gold");
	ob->set_amount(thecash/10000*2);
	ob->move(me);
	if((thecash % 10000)!=0) {
		ob1 = new("/clone/money/silver");
		ob1->set_amount((thecash-((thecash/10000*10000)))/100*2);
		ob1->move(me);
	}
	}
	me->set_temp("tmark/押",0);
	return 1;	
}

int pieshuang(object me)
{
	object ob,ob1;

	if(thecash<10000) {
	ob = new("/clone/money/silver");
	ob->set_amount(thecash/100*3);
	ob->move(me);	
	}
	else {
	ob = new("/clone/money/gold");
	ob->set_amount(thecash/10000*3);
	ob->move(me);
	if((thecash % 10000)!=0) {
		ob1 = new("/clone/money/silver");
		ob1->set_amount((thecash-((thecash/10000)*10000))/100*3);
		ob1->move(me);
	}
	}
	me->set_temp("tmark/押",0);
	return 1;
}

int yesorno()
{
	
	if (i1==1 || i2==1)
		if(sumi<12) 
			sumi=sumi+10;

	if (sumi>17) return sumi;
	else {
		if (sumi<14) {
			i3 = 1+random(13);
			if (i3>10) j3=10;
			else j3=i3;
			return sumi+j3;
		}
		else {
			if(random(21)>10) {
				i3 = 1+random(13);
				if (i3>10) j3=10;
				else j3=i3;
				return sumi+j3;
			}
			else return sumi;
		}
	}
}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}

string cstr(int i)
{
	switch(i) {
		case 1:
			return "Ａ";
		case 2:
			return "２";
		case 3:
			return "３";
		case 4: 
			return "４";
		case 5:
			return "５";
		case 6:
			return "６";
		case 7:
			return "７";
		case 8:
			return "８";
		case 9:
			return "９";
		case 10:
			return "Ｔ";
		case 11:
			return "Ｊ";
		case 12:
			return "Ｑ";
		case 13:
			return "Ｋ";
		default:
			return "";
	}
}