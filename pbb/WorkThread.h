#pragma once
#include <boost/signals2.hpp>
#include <boost/asio.hpp>
#include "doBuild.h"
#include "Utils.h"

class CWorkThread
{
public:
	CWorkThread(boost::asio::io_service &);
	~CWorkThread();

public:
	void run(std::wstring path, bool isGPU, std::string key = "");
private:
	void async_run(std::wstring path, bool isGPU, std::string key = "");

public:
	boost::signals2::signal <void(int)> sig_process;			// 进度
	boost::signals2::signal <void(std::wstring)> sig_message;	// 消息提示

	boost::signals2::signal <void(void)> sig_start;				// 开始
	boost::signals2::signal <void(void)> sig_end;				// 结束

private:
	boost::asio::io_context &_io_service;
	bool gpuCalc(pvKey key);
	bool cpuCalc(pvKey key);
	void dump(fInfo file, pvKey key);
};

