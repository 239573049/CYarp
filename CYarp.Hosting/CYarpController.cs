﻿using CYarp.Server;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.Logging;
using Microsoft.Net.Http.Headers;
using System;
using System.Security.Claims;
using System.Threading.Tasks;

namespace CYarp.Hosting
{
    [Authorize(Roles = "Mobile")]
    public class CYarpController : ControllerBase
    {
        private readonly IClientManager clientManager;
        private static readonly string clientIdClaimType = "ClientId";

        public CYarpController(IClientManager clientManager)
        {
            this.clientManager = clientManager;
        }

        [Route("/{**cyarp}")]
        public async Task InvokeAsync()
        {
            var clientId = this.User.FindFirstValue(clientIdClaimType);
            if (clientId != null && clientManager.TryGetValue(clientId, out var client))
            {
                this.Request.Headers.Remove(HeaderNames.Authorization);
                await client.ForwardHttpAsync(this.HttpContext);
            }
            else
            {
                this.Response.StatusCode = StatusCodes.Status502BadGateway;
            }
        }
    }
}